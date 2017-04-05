//
//  SafeBuffer.cpp
//
//
//  Created by Joshua Higginbotham on 11/4/15.
//
//

#include "SafeBuffer.h"

SafeBuffer::SafeBuffer() {
	pthread_mutex_init(&mutex, NULL);
}

SafeBuffer::~SafeBuffer() {
	pthread_mutex_destroy(&mutex);
}

int SafeBuffer::size() {
	pthread_mutex_lock(&mutex);
    return buffer.size();
	pthread_mutex_unlock(&mutex);
}

void SafeBuffer::push_back(std::string str) {
	pthread_mutex_lock(&mutex);
	buffer.push_back(str);
	pthread_mutex_unlock(&mutex);
}

std::string SafeBuffer::retrieve_front() {
	pthread_mutex_lock(&mutex);
	std::string front = buffer.front();
	buffer.pop_front();
	pthread_mutex_unlock(&mutex);
	return front;
}
