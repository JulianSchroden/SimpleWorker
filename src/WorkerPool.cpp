/**
 *  Copyright (c) 2019 Julian Schroden. All rights reserved.
 *  Licensed under the MIT License. See LICENSE file in the project root for
 *  full license information.
 */

#include <SimpleWorker/WorkerPool.h>

namespace SimpleWorker
{
WorkerPool::WorkerPool()
{
   start();
}

void WorkerPool::addWorker(Worker* const worker)
{
   worker->setWorkerPool(this);
   workers_.push_back(worker);
}

void WorkerPool::removeWorker(Worker* const worker)
{
   auto it = workers_.begin();
   while (it != workers_.end())
   {
      if (*it == worker)
      {
         it = workers_.erase(it);
         break;
      }
   }
}

void WorkerPool::runOnce()
{
   for (auto& worker : workers_)
   {
      switch (worker->state())
      {
         case WorkerState::Initial:
            break;
         case WorkerState::Running:
            worker->runOnce();
         case WorkerState::Paused:
            break;
         case WorkerState::Terminated:
            break;
      }
   }
}

}  // namespace SimpleWorker