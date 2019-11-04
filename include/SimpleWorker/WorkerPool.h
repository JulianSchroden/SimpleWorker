/**
 *  Copyright (c) 2017-2019 Julian Schroden. All rights reserved.
 *  Licensed under the MIT License. See LICENSE file in the project root for
 *  full license information.
 */

#ifndef _SIMPLE_WORKER_WORKER_POOL_h
#define _SIMPLE_WORKER_WORKER_POOL_h

#include <SimpleWorker/Worker.h>

#include <vector>


namespace SimpleWorker
{
class WorkerPool : public Worker
{
public:
   WorkerPool();

   //!
   //! Add a \a worker to the WorkerPool
   //!
   void addWorker(Worker* const worker);

   //!
   //! Remove a \a worker from the WorkerPool
   //!
   void removeWorker(Worker* const worker);

   //!
   //! Execute the \a runOnce() methods of all workers within the WorkerPool.
   //!
   void runOnce() override;

private:
   std::vector<Worker*> workers_;
};
}  // namespace SimpleWorker

#endif