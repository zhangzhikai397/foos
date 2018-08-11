#ifndef	TTY_H
#define	TTY_H
#include <inttypes.h>
#define	VGA_BASE	(uint16_t*)0xB8000
#define	VGA_WIDTH	80
#define	VGA_HEIGHT	25
#define	VGA_COORD(x,y)	((y)*VGA_WIDTH+(x))
#define	VGA_X(offset)	((offset)%VGA_WIDTH)
#define	VGA_Y(offset)	((offset)/VGA_WIDTH)
/* Keyboard */
#define	MAX_SCANCODE	58
#define	RELEASED(code)	((code) & 0x80)
#define	CTRL	0x1D
#define	LSHIFT	0x2A
#define	RSHIFT	0x36
#define	ENTER	0x1C
#define	ALT	0x38
#define	CAPS	0x3A
#define	BACKSPACE	0x0E

struct kbd_state{
	uint8_t ctrl:1;
	uint8_t shift:1;
	uint8_t alt:1;
	uint8_t caps:1;
	uint8_t irq:1;		// Used by TTY internal calls
	uint8_t special:1;	// Used by TTY internal calls as well
	uint8_t reserved:2;
} __attribute__((packed));

struct tty;
typedef void (*flushhandler_t)(struct tty*);

struct tty{
	uint8_t color;
	uint8_t cursor;
	char buf[512];
	char *bufptr;
	struct kbd_state kbd;
	flushhandler_t flush;
} __attribute__((packed));

extern struct tty *tty_current(void);
extern void tty_enable_cursor(uint8_t start,uint8_t end);
extern void tty_disable_cursor(void);
extern uint16_t tty_get_cursor(void);
extern void tty_update_cursor(struct tty *ptr,uint16_t offset);
extern void tty_writechar(struct tty *ptr,char c);
extern size_t tty_write(struct tty *ptr,const void *data,size_t len);
extern size_t tty_writestring(struct tty *ptr,const char *str);
extern size_t tty_read(struct tty *ptr,char *buf,int size);
extern int tty_create(struct tty *ptr);
/* Initialization before creating TTY */
extern int tty_init(void *reserved);
#endif
