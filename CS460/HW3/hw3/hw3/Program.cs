using System;
using System.IO;
namespace hw3
{
    class Program
    {
        // Print the command line usage for this program.
        private static void PrintUsage()
        {
            Console.WriteLine("Usage is:\n" +
                "\tjava Main C inputfile outputfile\n\n" +
                "Where:\n" +
                " C is the column number to fit to\n" +
                " inputfile is the input text file\n" +
                " outputfile is the new output file base name containing the wrapped text.\n" +
                "e.g. Program 72 myfile.txt myfile_wrapped.txt");
        }
        static void Main(string[] args)
        {
            int c = 72;

            string inputFilename;

            string outputFilename = "output.txt";

            StreamReader scanner = null;

            // Read the comand line arguments...
            if (args.Length != 3)
            {
                PrintUsage();

                Environment.Exit(1);
            }
            try
            {
                c = int.Parse(args[0]);

                inputFilename = args[1];

                outputFilename = args[2];

                scanner = new StreamReader(inputFilename);
            }
            catch(FileNotFoundException e)
            {
                Console.WriteLine("Could not find the input file.");

                Environment.Exit(1);

                throw e;
            }
            catch(Exception e)
            {
                Console.WriteLine("Something is wrong with the input.");

                PrintUsage();

                Environment.Exit(1);

                throw e;
            }
            IQueueInterface<string> words = new LinkedQueue<string>();

            string[] tempWords = scanner.ReadToEnd().Split(' ', '\n', '\r');

            for (int i = 0; i < tempWords.Length; i++)
            {
                if (tempWords[i] != "")
                {
                    words.Push(tempWords[i]);
                }
            }
            scanner.Close();

            int spaceRemaining = WrapSimply(words, c, outputFilename);

            Console.WriteLine("Total spaces remaining (Greedy): " + spaceRemaining);
        }
        private static int WrapSimply(IQueueInterface<string> words, int columnLength, string outputFilename)
        {
            StreamWriter output;
            try
            {
                output = new StreamWriter(outputFilename);
            }
            catch(FileNotFoundException e)
            {
                Console.WriteLine("Cannot create or open " + outputFilename + " for writing. Using standard output instead.");

                output = new StreamWriter(Console.OpenStandardOutput());

                throw e;
            }
            int col = 1;

            int spacesRemaining = 0;

            while (!words.IsEmpty())
            {
                string str = words.Peek();

                int len = str.Length;

                if (col == 1)
                {
                    output.Write(str);

                    col += len;

                    words.Pop();
                }
                else if ((col + len >= columnLength))
                {
                    output.WriteLine();

                    spacesRemaining += (columnLength - col) + 1;

                    col = 1;
                }
                else
                {
                    output.Write(" ");

                    output.Write(str);

                    col += (len + 1);

                    words.Pop();
                }
            }
            output.WriteLine();

            output.Flush();

            output.Close();

            return spacesRemaining;
        }
    }
}
