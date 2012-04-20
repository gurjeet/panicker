/* Module source file 'hi.c'. */  
#include <linux/module.h>      // for all modules 
#include <linux/init.h>        // for entry/exit macros 
#include <linux/kernel.h>      // for printk priority macros 
#include <asm/current.h>       // process information, just for fun 
#include <linux/sched.h>       // for "struct task_struct" 

/*
 * Derived from:
 * https://www.linux.com/learn/linux-career-center/23685-the-kernel-newbie-corner-your-first-loadable-kernel-module
 *
 * The code was originally dual licensed under BSD/GPL, I have retained that.
 */

#define MOD_NAME "Linux Panicker"

static int hi(void)
{
     printk(KERN_INFO MOD_NAME " module being loaded.\n");
     printk(KERN_INFO "User space process is '%s'\n", current->comm);
     printk(KERN_INFO "User space PID is  %i\n", current->pid);
     panic("Panicking on purpose.");
//     return 0;       // to show a successful load 
}  

/* This funtion will never be called, 'coz if the module was loaded, kernel
 * would've panicked and committed suicide.
*/
static void bye(void) 
{
     printk(KERN_INFO MOD_NAME " module being unloaded.\n"); 
}  

module_init(hi);     // what's called upon loading 
module_exit(bye);    // what's called upon unloading  

MODULE_AUTHOR("Gurjeet Singh"); 
MODULE_LICENSE("Dual BSD/GPL"); 
MODULE_DESCRIPTION("Causes the kernel to panic.");

