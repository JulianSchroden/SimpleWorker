/**
 *  Copyright (c) 2019 Julian Schroden. All rights reserved.
 *  Licensed under the MIT License. See LICENSE file in the project root for
 *  full license information.
 */

#include <SimpleWorker/Worker.h>
#include <SimpleWorker/WorkerPool.h>

namespace SimpleWorker
{
const char* toString(WorkerState workerState)
{
#define CASE(state_)         \
   case WorkerState::state_: \
      return #state_;
   switch (workerState)
   {
      CASE(Initial);
      CASE(Running);
      CASE(Paused);
      CASE(Terminated);
   }
#undef CASE
   return "";
}

Worker::Worker() {}

Worker::~Worker()
{
   terminate();
}

void Worker::setWorkerPool(WorkerPool* workerPool)
{
   workerPool_ = workerPool;
}

void Worker::start()
{
   if (workerState_ == WorkerState::Initial ||
       workerState_ == WorkerState::Paused)
   {
      workerState_ = WorkerState::Running;
   }
}

void Worker::pause()
{
   if (workerState_ == WorkerState::Running)
   {
      workerState_ = WorkerState::Paused;
   }
}

void Worker::terminate()
{
   workerState_ = WorkerState::Terminated;
   workerPool_->removeWorker(this);
}

WorkerState Worker::state() const
{
   return workerState_;
}

}  // namespace SimpleWorker