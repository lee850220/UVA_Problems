解法說明：
先建立一個最大總數N=10000的陣列，每次將第X(X>0)次讀入的資料放入陣列第X-1個位置，進行前X個陣列的sorting，若X為奇數輸出array[X/2]，若為偶數輸出(array[X/2]+array[X/2 - 1])*0.5。