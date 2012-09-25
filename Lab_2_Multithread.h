/*
 * Lab_2_Multithread.h
 *
 *  Created on: 25.09.2012
 *      Author:
 */

#ifndef LAB_2_MULTITHREAD_H_
#define LAB_2_MULTITHREAD_H_

namespace M_thread {
	extern pthread_barrier_t barrier_start;
	extern pthread_mutex_t mutex_cond_proc;
	extern pthread_cond_t cond_proc;
	extern short cur_proc;
	const short THREAD_1 = 1;
	const short THREAD_2 = 2;
}

#endif /* LAB_2_MULTITHREAD_H_ */


