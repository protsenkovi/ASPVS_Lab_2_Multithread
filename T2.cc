#ifndef HEADER
#include <cstdlib>
#include <iostream>
#include <pthread.h>
#define HEADER
#endif



pthread_attr_t thread_T2_init()
{
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	return attr;
}

void* thread_T2(void* arg)
{

}
