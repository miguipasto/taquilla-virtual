#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/string.h>

void crear_proceso(struct task_struct *task_list);
void restar_proceso(struct task_struct *task_list);
void matar_proceso(struct task_struct *task_list,int);
int reemplazo_no_prioritario(struct task_struct *task_list);
void temporizador(void);
