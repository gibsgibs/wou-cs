///Gabriel Brehm
///CS361
///Lab01
///Colaborators: Jacob Malmstadt


using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Office.Interop.Excel;
using excelFile = Microsoft.Office.Interop.Excel;

namespace cs361_lab01
{
    /// <summary>
    /// NOTE: The majority of the methods in this class came from the following tutorial: https://www.youtube.com/watch?v=lsv7rAsvYuA.
    /// I take zero credit for it.
    /// </summary>
    public class ExcelClass
    {
        string PathToFile = "";

        public _Application excel = new excelFile.Application();

        public Workbook Book;

        public Worksheet Sheet;
        /// <summary>
        /// Constructor for an excel object.
        /// </summary>
        /// <param name="pathToFile">
        /// The path and name to the excel file.
        /// </param>
        /// <param name="numOfSheets">
        /// The number of sheets in the workbook
        /// </param>
        public ExcelClass(string pathToFile, int numOfSheets)
        {
            PathToFile = pathToFile;

            Book = excel.Workbooks.Open(pathToFile);

            Sheet = Book.Worksheets[numOfSheets];
        }

        /// <summary>
        /// Reads the information form a cell. Note: this method is not used, but was part of the tutorial.
        /// </summary>
        /// <param name="row">
        /// The row number, indexed from 0.
        /// </param>
        /// <param name="column">
        /// The column number, indexed from 0.
        /// </param>
        /// <returns>
        /// If the cell contains a value, it is returned as a string. Otherwise, and empty string is returned.
        /// </returns>
        public string ReadCell(int row, int column)
        {
            row++;

            column++;

            if (Sheet.Cells[row, column].Value2 != null)
            {
                return Sheet.Cells[row, column];
            }
            else
            {
                return "";
            }
        }

        /// <summary>
        /// Wrties the given data to the indexed cell.
        /// </summary>
        /// <param name="row">
        /// The row number, indexed from 0.
        /// </param>
        /// <param name="column">
        /// The column number, indexed from 0.
        /// </param>
        /// <param name="data">
        /// The data to be inputed as a string.
        /// </param>
        public void WriteCell(int row, int column, string data)
        {
            row++;

            column++;

            Sheet.Cells[row, column].Value2 = data;
        }

        /// <summary>
        /// Saves the excel workbook.
        /// </summary>
        public void SaveExcel()
        {
            Book.Save();
        }

        /// <summary>
        /// Saves the excel workbook as the given name.
        /// </summary>
        /// <param name="pathToFile">
        /// The path and name of the file.
        /// </param>
        public void SaveAsExcel(string pathToFile)
        {
            Book.SaveAs(pathToFile);
        }

        /// <summary>
        /// Closes the workbook.
        /// </summary>
        public void CloseExcel()
        {
            Book.Close();
        }
    }
}
