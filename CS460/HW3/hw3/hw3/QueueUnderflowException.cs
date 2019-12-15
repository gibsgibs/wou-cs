using System;

namespace hw3
{
    public class QueueUnderflowException : SystemException
    {
        public QueueUnderflowException() : base()
        {}
        public QueueUnderflowException(string message) : base(message)
        {}
    }
}