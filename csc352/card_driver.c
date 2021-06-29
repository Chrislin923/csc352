/*
 * "cards, world!" minimal kernel module - /dev version
 *
 * Valerie Henson <val@nmt.edu>
 *
 */

#include <linux/fs.h>
#include <linux/init.h>
#include <linux/miscdevice.h>
#include <linux/module.h>

#include <linux/uaccess.h>
#include <linux/random.h>

/*
 * cards_read is the function called when a process calls read() on
 * /dev/cards.  It writes "cards, world!" to the buffer passed in the
 * read() call.
 */

static int c = 0;
static char cards[52];

unsigned char get_random_byte(int max) {
         unsigned char c;
         get_random_bytes(&c, 1);
         return c%max;
};

static ssize_t cards_read(struct file * file, char * buf, 
			  size_t count, loff_t *ppos)
{

	int i;

	
	if( c == 0){
		for(i =0; i< 52; i++){
			cards[i] = get_random_byte(52);
		}
	}

	copy_to_user(buf, &cards[c], 1);


	c += 1;

	if (c > 51)
		c = 0;
	

	*ppos = cards[c];
	return cards[c];

};





/*
 * The only file operation we care about is read.
 */

static const struct file_operations cards_fops = {
	.owner		= THIS_MODULE,
	.read		= cards_read,
	.llseek		= default_llseek,
};

static struct miscdevice cards_dev = {
	/*
	 * We don't care what minor number we end up with, so tell the
	 * kernel to just pick one.
	 */
	MISC_DYNAMIC_MINOR,
	/*
	 * Name ourselves /dev/cards.
	 */
	"cards",
	/*
	 * What functions to call when a program performs file
	 * operations on the device.
	 */
	&cards_fops
};

static int __init
cards_init(void)
{
	int ret;

	/*
	 * Create the "cards" device in the /sys/class/misc directory.
	 * Udev will automatically create the /dev/cards device using
	 * the default rules.
	 */

	ret = misc_register(&cards_dev);
	if (ret)
		printk(KERN_ERR
		       "Unable to register \"cards, world!\" misc device\n");

	return ret;
}

module_init(cards_init);

static void __exit
cards_exit(void)
{
	misc_deregister(&cards_dev);
}

module_exit(cards_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Valerie Henson <val@nmt.edu>");
MODULE_DESCRIPTION("\"cards, world!\" minimal module");
MODULE_VERSION("dev");
