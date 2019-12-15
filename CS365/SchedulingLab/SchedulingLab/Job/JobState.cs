namespace SchedulingLab
{
    public enum JobState
    {
        New,
        Ready,
        Preempted,
        StillRunning,
        Sleeping,
        Idling,
        Exited,
        IO,
        Swapped
    }
}
