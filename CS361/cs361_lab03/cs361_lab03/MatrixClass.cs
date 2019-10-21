using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cs361_lab03
{
    class MatrixClass
    {
        /// <summary>
        /// The matrix chain order algorithm to determin the number of scalar multiplications required to compute 
        /// the product of the matrices of the given sizes.
        /// Sources: https://www.geeksforgeeks.org/csharp-program-for-matrix-chain-multiplication-dp-8/.
        /// </summary>
        /// <param name="pArray">
        /// The array that represents the dimensions of the the matrices to be multiplied.
        /// </param>
        /// <returns>
        /// Returns the two tables in a list; the m table which holds the number of multiplications to get to that point,
        /// and the s table which holds the k value for the minimum number of scalar multiplications.
        /// </returns>
        public static List<int[,]> MatrixChainOrder(int[] pArray)
        {
            int n = pArray.Length;

            int[,] mTable = new int[n, n];

            int[,] sTable = new int[n, n];

            for (int i = 0; i < n; i++)
            {
                mTable[i, i] = 0;
            }
            for (int l = 2; l < n; l++)
            {
                for (int i = 1; i < n - l + 1; i++)
                {
                    int j = i + l - 1;

                    mTable[i, j] = int.MaxValue;

                    for (int k = i; k < j; k++)
                    {
                        int q = mTable[i, k] + mTable[k + 1, j] + 
                                (pArray[i - 1] * pArray[k] * pArray[j]);

                        if (q < mTable[i, j])
                        {
                            mTable[i, j] = q;

                            sTable[i, j] = k;
                        }
                    }
                }
            }
            List<int[,]> result = new List<int[,]>();

            result.Add(mTable);

            result.Add(sTable);

            return result;
        }

        /// <summary>
        /// Uses the memoized version of the matrix chain order algorithm to determin the number of scalar 
        /// multiplications required to compute the product of the matrices of the given sizes.
        /// </summary>
        /// <param name="pArray">
        /// The array that represents the dimensions of the the matrices to be multiplied.
        /// </param>
        /// <returns>
        /// Returns the two tables in a list; the m table which holds the number of multiplications to get to that point, 
        /// and the s table which holds the k value for the minimum number of scalar multiplications.
        /// </returns>
        public static List<int[,]> MemoizedMatrixChain(int[] pArray)
        {
            int n = pArray.Length;

            int[,] mTable = new int[n, n];

            int[,] sTable = new int[n, n];

            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    mTable[i, j] = -1;
                }
            }
            LookupChain(mTable, sTable, pArray, 1, n - 1);

            List<int[,]> result = new List<int[,]>();

            result.Add(mTable);

            result.Add(sTable);

            return result;
        }

        /// <summary>
        /// The recusrsive part of the memoized vesion of the matrix chain multiplication. 
        /// Recursivley retermins the number of scalar multiplications needed to compute the product of the matrices of the given sizes.
        /// </summary>
        /// <param name="mTable">
        /// The table that holds the number of required scalar multiplications.
        /// </param>
        /// <param name="sTable">
        /// The table that holds the k value associated with the minimun number of scalar multiplications.
        /// </param>
        /// <param name="pArray">
        /// The array that represents the dimensions of the the matrices to be multiplied.
        /// </param>
        /// <param name="i">
        /// The row index.
        /// </param>
        /// <param name="j">
        /// The column index.
        /// </param>
        /// <returns>
        /// The minimum number of scalar multiplications to get to that point.
        /// </returns>
        public static int LookupChain(int[,] mTable, int[,] sTable, int[] pArray, int i, int j)
        {
            if(mTable[i, j] != -1)
            {
                return mTable[i, j];
            }
            if(i == j)
            {
                mTable[i, j] = 0;
            }
            else
            {
                for (int k = i; k < j; k++)
                {
                    int q = LookupChain(mTable, sTable, pArray, i, k) +
                            LookupChain(mTable, sTable, pArray, k + 1, j) +
                            (pArray[i - 1] * pArray[k] * pArray[j]);
                    if (q < mTable[i, j] || mTable[i, j] == -1)
                    {
                        mTable[i, j] = q;
                        sTable[i, j] = k;
                    }
                }
            }
            return mTable[i, j];
        }

        /// <summary>
        /// Prints out the chain of matrix multiplications with optimal parentheses placement.
        /// This method is recusrive.
        /// </summary>
        /// <param name="tableS">
        /// The S table found from the matrix chain multiplication algorithm method.
        /// </param>
        /// <param name="i">
        /// The row index.
        /// </param>
        /// <param name="j">
        /// The column index.
        /// </param>
        public static string PrintOptimalParens(int[,] tableS, int i, int j)
        {
            if(i == j)
            {
                return "A" + i.ToString(); 
            }
            else
            {
                return "(" + PrintOptimalParens(tableS, i, tableS[i, j]) + PrintOptimalParens(tableS, tableS[i, j] + 1, j) + ")";
            }
        }
    }
}
