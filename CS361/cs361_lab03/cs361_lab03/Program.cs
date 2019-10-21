using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cs361_lab03
{
    class Program
    {
        public static void Main(string[] args)
        {
            int[] array = { 30, 4, 8, 5, 10, 25, 15 };

            List<int[,]> tables_mco = MatrixClass.MatrixChainOrder(array);

            GenFunctions.PrintTable("Matrix Chain Order \nM Table with p = { 30, 4, 8, 5, 10, 25, 15 }", tables_mco[0]);

            GenFunctions.PrintTable("Matrix Chain Order \nS Table with p = { 30, 4, 8, 5, 10, 25, 15 }", tables_mco[1]);

            Console.WriteLine("Matrix Chain Order \nOptimally Parenthesized Form");

            GenFunctions.TextBox(MatrixClass.PrintOptimalParens(tables_mco[1], 1, array.Length - 1));

            List<int[,]> tables_mmc = MatrixClass.MemoizedMatrixChain(array);

            GenFunctions.PrintTable("Memoized Matrix Chain \nM Table with p = { 30, 4, 8, 5, 10, 25, 15 }", tables_mmc[0]);

            GenFunctions.PrintTable("Memoized Matrix Chain \nS Table with p = { 30, 4, 8, 5, 10, 25, 15 }", tables_mmc[1]);

            Console.WriteLine("Memoized Matrix Chain \nOptimally Parenthesized Form");

            GenFunctions.TextBox(MatrixClass.PrintOptimalParens(tables_mmc[1], 1, array.Length - 1));

            List<Vertex> myVertices = new List<Vertex>();

            Vertex A = new Vertex("A"); myVertices.Add(A);
            Vertex B = new Vertex("B"); myVertices.Add(B);
            Vertex C = new Vertex("C"); myVertices.Add(C);
            Vertex D = new Vertex("D"); myVertices.Add(D);
            Vertex E = new Vertex("E"); myVertices.Add(E);
            Vertex F = new Vertex("F"); myVertices.Add(F);
            Vertex G = new Vertex("G"); myVertices.Add(G);
            Vertex H = new Vertex("H"); myVertices.Add(H);
            Vertex I = new Vertex("I"); myVertices.Add(I);
            Vertex J = new Vertex("J"); myVertices.Add(J);
            Vertex K = new Vertex("K"); myVertices.Add(K);
            Vertex L = new Vertex("L"); myVertices.Add(L);
            Vertex M = new Vertex("M"); myVertices.Add(M);
            Vertex N = new Vertex("N"); myVertices.Add(N);
       
            AdjacencyList adjacencyList = new AdjacencyList(myVertices.Count);

            adjacencyList.AddEdge(A, B);
            adjacencyList.AddEdge(A, D);

            adjacencyList.AddEdge(B, A);
            adjacencyList.AddEdge(B, C);

            adjacencyList.AddEdge(C, B);
            adjacencyList.AddEdge(C, M);
            adjacencyList.AddEdge(C, N);

            adjacencyList.AddEdge(D, A);
            adjacencyList.AddEdge(D, E);
            adjacencyList.AddEdge(D, F);
            adjacencyList.AddEdge(D, G);
            adjacencyList.AddEdge(D, N);

            adjacencyList.AddEdge(E, D);
            adjacencyList.AddEdge(E, F);

            adjacencyList.AddEdge(F, D);
            adjacencyList.AddEdge(F, E);
            adjacencyList.AddEdge(F, H);

            adjacencyList.AddEdge(G, D);
            adjacencyList.AddEdge(G, H);
            adjacencyList.AddEdge(G, J);

            adjacencyList.AddEdge(H, F);
            adjacencyList.AddEdge(H, G);
            adjacencyList.AddEdge(H, I);
            adjacencyList.AddEdge(H, K);

            adjacencyList.AddEdge(I, H);
            adjacencyList.AddEdge(I, J);

            adjacencyList.AddEdge(J, G);
            adjacencyList.AddEdge(J, I);
            adjacencyList.AddEdge(J, K);
            adjacencyList.AddEdge(J, N);

            adjacencyList.AddEdge(K, H);
            adjacencyList.AddEdge(K, J);
            adjacencyList.AddEdge(K, L);

            adjacencyList.AddEdge(L, K);
            adjacencyList.AddEdge(L, M);

            adjacencyList.AddEdge(M, C);
            adjacencyList.AddEdge(M, L);
            adjacencyList.AddEdge(M, N);

            adjacencyList.AddEdge(N, C);
            adjacencyList.AddEdge(N, D);
            adjacencyList.AddEdge(N, J);
            adjacencyList.AddEdge(N, M);

            Searches.BreadthFitstSearch_al(adjacencyList, myVertices, A);

            Vertex.PrintVertexInfo(myVertices);

            int[,] adjacencyMatrix = new int[myVertices.Count(), myVertices.Count()];

            adjacencyMatrix[0, 1] = 1;
            adjacencyMatrix[0, 3] = 1;

            adjacencyMatrix[1, 0] = 1;
            adjacencyMatrix[1, 2] = 1;

            adjacencyMatrix[2, 1] = 1;
            adjacencyMatrix[2, 12] = 1;
            adjacencyMatrix[2, 13] = 1;

            adjacencyMatrix[3, 0] = 1;
            adjacencyMatrix[3, 4] = 1;
            adjacencyMatrix[3, 5] = 1;
            adjacencyMatrix[3, 6] = 1;
            adjacencyMatrix[3, 13] = 1;

            adjacencyMatrix[4, 3] = 1;
            adjacencyMatrix[4, 5] = 1;

            adjacencyMatrix[5, 3] = 1;
            adjacencyMatrix[5, 4] = 1;
            adjacencyMatrix[5, 7] = 1;

            adjacencyMatrix[6, 3] = 1;
            adjacencyMatrix[6, 7] = 1;
            adjacencyMatrix[6, 9] = 1;

            adjacencyMatrix[7, 5] = 1;
            adjacencyMatrix[7, 6] = 1;
            adjacencyMatrix[7, 8] = 1;
            adjacencyMatrix[7, 10] = 1;

            adjacencyMatrix[8, 7] = 1;
            adjacencyMatrix[8, 9] = 1;

            adjacencyMatrix[9, 6] = 1;
            adjacencyMatrix[9, 8] = 1;
            adjacencyMatrix[9, 10] = 1;
            adjacencyMatrix[9, 13] = 1;

            adjacencyMatrix[10, 7] = 1;
            adjacencyMatrix[10, 9] = 1;
            adjacencyMatrix[10, 11] = 1;

            adjacencyMatrix[11, 10] = 1;
            adjacencyMatrix[11, 12] = 1;

            adjacencyMatrix[12, 2] = 1;
            adjacencyMatrix[12, 11] = 1;
            adjacencyMatrix[12, 13] = 1;

            adjacencyMatrix[13, 2] = 1;
            adjacencyMatrix[13, 3] = 1;
            adjacencyMatrix[13, 9] = 1;
            adjacencyMatrix[13, 12] = 1;

            GenFunctions.PrintTable("Adjacency Matrix", adjacencyMatrix);

            int[,] result = Searches.BreadthFirstSearch_am(adjacencyMatrix);

            GenFunctions.PrintTable("Breadth First Search", result);

            GenFunctions.TextBox("Press ENTER to Exit");

            Console.Read();
        }
    }
}
