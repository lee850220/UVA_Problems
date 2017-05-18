解題方法：
這題為All pairs shortest paths Problem，透過DP解題，使用三重迴圈，DP[i][j]=min(DP[i][j], DP[i][k]+DP[k][j])，最後將比較各列元素總和，最小的即答案。