#ifndef GTHREAD_POOL
#define GTHREAD_POOL

#include "pool.h"
/*******************************************************
 * name:Gthread_pool_init
 * des:this func will init Gthread_pool struct
 * para1: the pointer point to a Gthread_pool struct
 * para2:max number of tasks
 * para3:max number of workers
 * para4:min number of workers
 * return: state, SUCCESS or FAILURE
 * ****************************************************/
int Gthread_pool_init(struct Gthread_pool * pool, int max_tasks, int max_workers, int min_workers);


/* ***********************************************************************************************************
 *name:close_pool
 *description:close the pool
 *para1: a pointer point to a pool
 *return SUCCESS or FAILURE
 *************************************************************************************************************/
int close_pool(struct Gthread_pool * pool);


/* ***********************************************************************************************************
 *name:add_job
 *description:add a task to this pool
 *para1: a pointer point to a pool
 *para2:a pointer point to a fucntion like this: void * (* func)(void * arg)
 *return SUCCESS or FAILURE
 *************************************************************************************************************/
int add_job(struct Gthread_pool * pool, void * (* job)(void * arg), void * arg);
#endif
	
