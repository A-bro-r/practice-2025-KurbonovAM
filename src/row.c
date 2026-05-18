#include "sudoku.h"

int checkRows(Square *** sudoku, Box ** boxes)
{
  int i, j, k;
  int sum[9];
  int place[9];

  // цикл через все столбцы
  for (i = 0; i < 9; i++)
  {

    for(j = 0; j < 9; j++)
    {
      sum[j] = 0;
      place[j] = 0;
    }

    // цикл через каждый квадрат в столбце
    for (j = 0; j < 9; j++)
    {
      if(sudoku[i][j] -> number != 0) continue;

      // цикл через все возможные варианты
      for (k = 0; k < 9; k++)
      {
        // проверка возможен ли (к)
        if (sudoku[i][j] -> possible[k] == 0)
        {
          sum[k]++;
          place[k] = j;
        }
      }
    }

    for(k = 0; k < 9; k++)
    {
      if (sum[k] == 1)
      {
        sudoku[i][place[k]] ->number = k+1;
        sudoku[i][place[k]] ->solvable = 0;
        UNSOLVED--;

        updateSudoku(sudoku, i, place[k]);
        updateBoxes(sudoku, i, place[k]);

        return 1;
      }
    }


  }
  return 0;
}
