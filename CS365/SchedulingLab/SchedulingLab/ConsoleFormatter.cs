using System;

namespace SchedulingLab
{
    class ConsoleFormatter
    {
        public static string WhiteSpaceFill(string text, int colWidth)
        {
            if (text.Length > colWidth) throw new InvalidOperationException("Text is larger than column.");
            var whiteSpace = string.Empty;
            for (var i = 0; i < colWidth - text.Length; i++)
            {
                whiteSpace = $"{whiteSpace} ";
            }
            return whiteSpace;
        }

        public static void PrintColumnedLine(int numOfCols, int colWidth)
        {
            var result = "+";
            for (var i = 0; i < numOfCols; i++)
            {
                var line = string.Empty;
                for (var j = 0; j < colWidth; j++)
                {
                    line = $"{line}-";
                }
                result = $"{result}{line}+";
            }
            Console.WriteLine(result);
        }
    }
}
