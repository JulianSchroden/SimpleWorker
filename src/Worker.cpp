#include <SimpleWorker/Worker.h>

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
}

Worker::Worker() {}

void Worker::startWorker()
{
   if (workerState_ == WorkerState::Initial ||
       workerState_ == WorkerState::Paused)
   {
      workerState_ = WorkerState::Running;
   }
}

void Worker::pauseWorker()
{
   if (workerState_ == WorkerState::Running)
   {
      workerState_ = WorkerState::Paused;
   }
}

void Worker::terminateWorker()
{
   workerState_ = WorkerState::Terminated;
}

WorkerState Worker::state() const
{
    return workerState_;
}

}  // namespace SimpleWorker