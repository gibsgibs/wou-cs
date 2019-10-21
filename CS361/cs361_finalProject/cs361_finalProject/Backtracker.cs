using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cs361_finalProject
{
    class Backtracker
    {
        private readonly int row;

        private readonly int column;

        private readonly string value;

        public Backtracker(int row, int column, string value)
        {
            this.row = row;

            this.column = column;

            this.value = value;
        }

        public int GetRow()
        {
            return row;
        }

        public int GetColumn()
        {
            return column;
        }

        public string GetValue()
        {
            return value;
        }
    }
}