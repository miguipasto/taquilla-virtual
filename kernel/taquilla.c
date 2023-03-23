#include <linux/taquilla.h>
#include <linux/string.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <linux/pid.h>
#include <linux/signal.h>

#define MAX_PROCESOS 10
#define FRONTERA_PROCESOS 7
#define T_MAX 1500 //Ticks en 10 segundos

int num_procesos = 0;

void crear_proceso(struct task_struct *task_list){

  struct sched_param prioridad;  
  int busqueda_no_prio=0;

  if(strcmp(task_list->comm,"mantenimiento")==0){
    num_procesos++;
    prioridad.sched_priority=60;
    if(num_procesos < MAX_PROCESOS){
      sched_setscheduler(task_list,SCHED_FIFO,&prioridad);
      printk("TQ+Nuevo proceso de %s (%d), hay %d procesos en el sistema\n",task_list->comm,task_list->pid,num_procesos);
    } else {
      busqueda_no_prio = reemplazo_no_prioritario(task_list);
      if(busqueda_no_prio!=0){
        printk("Se ha encontrado un proceso para reemplazar\n");
        sched_setscheduler(task_list,SCHED_FIFO,&prioridad);
        printk("TQ+Nuevo proceso de %s (%d), hay %d procesos en el sistema\n",task_list->comm,task_list->pid,num_procesos);
      }else{
        printk("TQ+Sistema saturado, no hemos podido añadir el proceso de %s (%d) al sistema\n",task_list->comm,task_list->pid);
        matar_proceso(task_list,task_list->pid);
      }
    }
  }else if(strcmp(task_list->comm,"administracion")==0){
    num_procesos++;
    prioridad.sched_priority=55;
    if(num_procesos < MAX_PROCESOS){
      sched_setscheduler(task_list,SCHED_FIFO,&prioridad);
      printk("TQ+Nuevo proceso de %s (%d), hay %d procesos en el sistema\n",task_list->comm,task_list->pid,num_procesos);
    } else {
      busqueda_no_prio = reemplazo_no_prioritario(task_list);
      if(busqueda_no_prio!=0){
        printk("Se ha encontrado un proceso para reemplazar\n");
        sched_setscheduler(task_list,SCHED_FIFO,&prioridad);
        printk("TQ+Nuevo proceso de %s (%d), hay %d procesos en el sistema\n",task_list->comm,task_list->pid,num_procesos);
      }else{
        printk("TQ+Sistema saturado, no hemos podido añadir el proceso de %s (%d) al sistema\n",task_list->comm,task_list->pid);
        matar_proceso(task_list,task_list->pid);
      }
    } 
  }else if(strcmp(task_list->comm,"pagos")==0){
    num_procesos++;
    prioridad.sched_priority=50;
    if(num_procesos < FRONTERA_PROCESOS){
      sched_setscheduler(task_list,SCHED_RR,&prioridad);
      printk("TQ+Nuevo proceso de %s (%d), hay %d procesos en el sistema\n",task_list->comm,task_list->pid,num_procesos);
    } else {
      printk("TQ+Sistema saturado, no hemos podido añadir el proceso de %s (%d) al sistema\n",task_list->comm,task_list->pid);
      matar_proceso(task_list,task_list->pid);
    }
  }else if(strcmp(task_list->comm,"anulacion")==0){
    num_procesos++;
    prioridad.sched_priority=45;
    if(num_procesos < FRONTERA_PROCESOS){
      sched_setscheduler(task_list,SCHED_RR,&prioridad);
      printk("TQ+Nuevo proceso de %s (%d), hay %d procesos en el sistema\n",task_list->comm,task_list->pid,num_procesos);
    } else {
      printk("TQ+Sistema saturado, no hemos podido añadir el proceso de %s (%d) al sistema\n",task_list->comm,task_list->pid);
      matar_proceso(task_list,task_list->pid);
    }
  } else if(strcmp(task_list->comm,"reservas")==0){
    num_procesos++;
    prioridad.sched_priority=40;
    if(num_procesos < FRONTERA_PROCESOS){
      sched_setscheduler(task_list,SCHED_RR,&prioridad);
      printk("TQ+Nuevo proceso de %s (%d), hay %d procesos en el sistema\n",task_list->comm,task_list->pid,num_procesos);
    } else {
      printk("TQ+Sistema saturado, no hemos podido añadir el proceso de %s (%d) al sistema\n",task_list->comm,task_list->pid);
      matar_proceso(task_list,task_list->pid);
    }
  }else if(strcmp(task_list->comm,"consultas")==0){
    num_procesos++;
    prioridad.sched_priority=35;
    if(num_procesos < FRONTERA_PROCESOS){
      sched_setscheduler(task_list,SCHED_RR,&prioridad);
      printk("TQ+Nuevo proceso de %s (%d), hay %d procesos en el sistema\n",task_list->comm,task_list->pid,num_procesos);
    } else {
      printk("TQ+Sistema saturado, no hemos podido añadir el proceso de %s (%d) al sistema\n",task_list->comm,task_list->pid);
      matar_proceso(task_list,task_list->pid);
    }
  }
}

void restar_proceso(struct task_struct *task_list){
  if(strcmp(task_list->comm,"mantenimiento")==0){
    num_procesos--;  
    printk(KERN_INFO "TQ-El proceso de %s con pid %d ha acabado, tenemos %d procesos en el sistema\n",task_list->comm,task_list->pid,num_procesos);
  }else if(strcmp(task_list->comm,"administracion")==0){
    num_procesos--;  
    printk(KERN_INFO "TQ-El proceso de %s con pid %d ha acabado, tenemos %d procesos en el sistema\n",task_list->comm,task_list->pid,num_procesos);
  }else if(strcmp(task_list->comm,"pagos")==0){
    num_procesos--;  
    printk(KERN_INFO "TQ-El proceso de %s con pid %d ha acabado, tenemos %d procesos en el sistema\n",task_list->comm,task_list->pid,num_procesos);
  }else if(strcmp(task_list->comm,"anulacion")==0){
    num_procesos--;  
    printk(KERN_INFO "TQ-El proceso de %s con pid %d ha acabado, tenemos %d procesos en el sistema\n",task_list->comm,task_list->pid,num_procesos);
  }else if(strcmp(task_list->comm,"reservas")==0){
    num_procesos--;  
    printk(KERN_INFO "TQ-El proceso de %s con pid %d ha acabado, tenemos %d procesos en el sistema\n",task_list->comm,task_list->pid,num_procesos);
  }else if(strcmp(task_list->comm,"consultas")==0){
    num_procesos--;  
    printk(KERN_INFO "TQ-El proceso de %s con pid %d ha acabado, tenemos %d procesos en el sistema\n",task_list->comm,task_list->pid,num_procesos);
  }
}

int reemplazo_no_prioritario(struct task_struct *task_list){
  int i=0;
  for_each_process(task_list){
    if(strcmp(task_list->comm,"pagos")==0){
      matar_proceso(task_list,task_list->pid);
      i=1;
      break;
    }else if(strcmp(task_list->comm,"anulacion")==0){
      matar_proceso(task_list,task_list->pid);
      i=1;
      break;
    }else if(strcmp(task_list->comm,"reservas")==0){
      matar_proceso(task_list,task_list->pid);
      i=1;
      break;
    }else if(strcmp(task_list->comm,"consultas")==0){
      matar_proceso(task_list,task_list->pid);
      i=1;
      break;
    }
  }
  return i;
}

void matar_proceso(struct task_struct *task_list, pid_t pid){
  if(task_list->pid==pid){
    kill_pid(find_vpid(pid),SIGKILL,1);
    printk(KERN_INFO "TQ-Se ha matado el proceso %s con pid: %d\n",task_list->comm,pid);
  }
}

void temporizador(){
  struct task_struct *task_list;
  for_each_process(task_list){
    if(strcmp(task_list->comm,"mantenimiento")==0){
      if(task_list->utime >= T_MAX) {
        printk("TQ-Se ha encontrado un proceso de %s (%d) que ha superado el tiempo limiite en el sistema\n",task_list->comm,task_list->pid);
        matar_proceso(task_list,task_list->pid);
      }
    }else if(strcmp(task_list->comm,"administracion")==0){
      if(task_list->utime >= T_MAX) {
        printk("TQ-Se ha encontrado un proceso de %s (%d) que ha superado el tiempo limiite en el sistema\n",task_list->comm,task_list->pid);
        matar_proceso(task_list,task_list->pid);
      }
    }else if(strcmp(task_list->comm,"pagos")==0){
      if(task_list->utime >= T_MAX) {
        printk("TQ-Se ha encontrado un proceso de %s (%d) que ha superado el tiempo limite en el sistema\n",task_list->comm,task_list->pid);
        matar_proceso(task_list,task_list->pid);
      }
    }else if(strcmp(task_list->comm,"anulacion")==0){
      if(task_list->utime >= T_MAX) {
        printk("TQ-Se ha encontrado un proceso de %s (%d) que ha superado el tiempo limite en el sistema\n",task_list->comm,task_list->pid);
        matar_proceso(task_list,task_list->pid);
      }
    }else if(strcmp(task_list->comm,"reservas")==0){
      if(task_list->utime >= T_MAX) {
        printk("TQ-Se ha encontrado un proceso de %s (%d) que ha superado el tiempo limite en el sistema\n",task_list->comm,task_list->pid);
        matar_proceso(task_list,task_list->pid);
      }
    }else if(strcmp(task_list->comm,"consultas")==0){
      if(task_list->utime >= T_MAX) {
        printk("TQ-Se ha encontrado un proceso de %s (%d) que ha superado el tiempo limite en el sistema\n",task_list->comm,task_list->pid);
        matar_proceso(task_list,task_list->pid);
      }
    }
  }
}