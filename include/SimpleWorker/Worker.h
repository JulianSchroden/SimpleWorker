/**
 *  Copyright (c) 2017-2019 Julian Schroden. All rights reserved.
 *  Licensed under the MIT License. See LICENSE file in the project root for
 *  full license information.
 */

#ifndef _SIMPLE_WORKER_WORKER_h
#define _SIMPLE_WORKER_WORKER_h

namespace SimpleWorker
{
enum class WorkerState
{
   Initial,
   Running,
   Paused,
   Terminated,
};

const char* toString(WorkerState workerState);

class WorkerPool;

class Worker
{
public:
   Worker();

   virtual ~Worker();

   //!
   //! Setter for the managing \a workerPool.
   //! This is required so that the Worker can unregister itself when beeing
   //! destroyed.
   //!
   void setWorkerPool(WorkerPool* workerPool);

   //!
   //! Start the Worker.
   //!
   void startWorker();

   //!
   //! Pause the Worker.
   //!
   void pauseWorker();

   //!
   //! Terminate the Worker.
   //!
   void terminateWorker();

   //!
   //! Get the WorkerState of the Worker.
   //!
   WorkerState state() const;

   //!
   //! Abstract callback which needs to be implemented by the derived classes.
   //! Is called to perform the actual work and has to be non blocking and as
   //! quick as possible, to not delay other Worker executions too much.
   //!
   virtual void runOnce() = 0;

private:
   WorkerState workerState_ = WorkerState::Initial;
   WorkerPool* workerPool_;
};
}  // namespace SimpleWorker

#endif