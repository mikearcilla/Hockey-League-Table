/*
 ============================================================================
 Name        : A3P2Tests.c
 Author      : Mike
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

	int i;

	/* Conference A & B Scan */
	int count_A = 25;
	int count_B = 25;
	char team_A[count_A][26];
	int stats_A[count_A][4];
	char team_B[count_B][26];
	int stats_B[count_B][4];
	char conference_A[20];
	char conference_B[20];

	scanf("%s", conference_A);
	scanf("%d", &count_A);
	for(i = 0;i < count_A; i++){
		scanf("%s%d%d%d%d",team_A[i], &stats_A[i][0], &stats_A[i][1], &stats_A[i][2], &stats_A[i][3]);
	}

	scanf("%s", conference_B);
	scanf("%d", &count_B);
	for(i = 0;i < count_B; i++){
		scanf("%s%d%d%d%d", team_B[i], &stats_B[i][0], &stats_B[i][1], &stats_B[i][2], &stats_B[i][3]);
	}

/*
		// Conference A array print test
			printf("%s  ", conference_A);
			printf("%d\n", count_A);
			printf("%-25.s%s%7s%7s%7s\n", conference_A, "GW", "GL", "LOT", "LS");
			for(i = 0;i < count_A; i++){
				printf("%-25s%d%7d%7d%7d\n", team_A[i], stats_A[i][0], stats_A[i][1], stats_A[i][2], stats_A[i][3]);
			}

			printf("\n");

		// Conference B array print test
			printf("%s  ", conference_B);
			printf("%d\n", count_B);
			printf("%-25.s%s%7s%7s%7s\n", conference_B, "GW", "GL", "LOT", "LS");
			for(i = 0;i < count_B; i++){
				printf("%-25s%d%7d%7d%7d\n", team_B[i], stats_B[i][0], stats_B[i][1], stats_B[i][2], stats_B[i][3]);
			}

			printf("\n");
*/
		/* Compute Games Played */

	int played_A[count_A][1];
	int gpsum_A;
	for (i = 0; i < count_A; i++){
		gpsum_A = stats_A[i][0] + stats_A[i][1] + stats_A[i][2] + stats_A[i][3];
		played_A[i][0] = gpsum_A;
	}

/*
	printf("Games Played A:\n");
	for (i = 0; i < count_A; i++){
	printf("%d\n", played_A[i][0]);
	}
*/

//printf("\n");

	int played_B[count_B][1];
	int gpsum_B;
	for (i = 0; i < count_B; i++){
		gpsum_B = stats_B[i][0] + stats_B[i][1] + stats_B[i][2] + stats_B[i][3];
		played_B[i][0] = gpsum_B;
	}

/*
	printf("Games Played B:\n");
	for (i = 0; i < count_B; i++){
		printf("%d\n", played_B[i][0]);
	}
*/

	/* Compute Total Points */

	//Points A
	int points_A[count_A][1];
	int points_B[count_B][1];
	int pts_W_A, pts_OTL_A, pts_SL_A;
	int pts_W_B, pts_OTL_B, pts_SL_B;

	for (i = 0; i < count_A; i++){
		pts_W_A = 2 * stats_A[i][0];
		pts_OTL_A = stats_A[i][2];
		pts_SL_A = stats_A[i][3];
		points_A[i][0] = pts_W_A + pts_OTL_A + pts_SL_A;
	}

	/*
	printf("points A:\n");
	for (i = 0; i < count_A; i++){
		printf("%d\n", points_A[i][0]);
	}
*/

	//Points B
	for (i = 0; i < count_B; i++){
		pts_W_B = 2 * stats_B[i][0];
		pts_OTL_B = stats_B[i][2];
		pts_SL_B = stats_B[i][3];
		points_B[i][0] = pts_W_B + pts_OTL_B + pts_SL_B;
	}

/*
  	printf("points B:\n");
	for (i = 0; i < count_B; i++){
		printf("%d\n", points_B[i][0]);
	}
*/

	//printf("\n\n\n");

	/* Points from Greatest to Least */

	//Rework for Conference A
	int j, temp;
	char tempc[26];

	for(i = 0; i < count_A; i++){
		for( j = i + 1; j < count_A; j++){
			if(points_A[i][0] < points_A[j][0]){
				// swap name
				strcpy(tempc, team_A[i]);
				strcpy(team_A[i], team_A[j]);
				strcpy(team_A[j], tempc);
				// swap GP
				temp = played_A[i][0];
				played_A[i][0] = played_A[j][0];
				played_A[j][0] = temp;
				// swap Wins
				temp = stats_A[i][0];
				stats_A[i][0] = stats_A[j][0];
				stats_A[j][0] = temp;
				// swap Losses
				temp = stats_A[i][1];
				stats_A[i][1] = stats_A[j][1];
				stats_A[j][1] = temp;
				// swap OTL
				temp = stats_A[i][2];
				stats_A[i][2] = stats_A[j][2];
				stats_A[j][2] = temp;
				// swap SL
				temp = stats_A[i][3];
				stats_A[i][3] = stats_A[j][3];
				stats_A[j][3] = temp;
				// swap points
				temp = points_A[i][0];
				points_A[i][0] = points_A[j][0];
				points_A[j][0] = temp;
			}
		}
	}

	//Sort Alphabetically if same PTS
	for(i = 0; i < count_A; i++){
		if(points_A[i][0] == points_A[i + 1][0]){
			if(strcmp(team_A[i],team_A[i + 1]) > 0){
				strcpy(tempc, team_A[i]);
				strcpy(team_A[i], team_A[i + 1]);
				strcpy(team_A[i + 1], tempc);
				temp = played_A[i][0];
				played_A[i][0] = played_A[i + 1][0];
				played_A[i + 1][0] = temp;
				temp = stats_A[i][0];
				stats_A[i][0] = stats_A[i + 1][0];
				stats_A[i + 1][0] = temp;
				temp = stats_A[i][1];
				stats_A[i][1] = stats_A[i + 1][1];
				stats_A[i + 1][1] = temp;
				temp = stats_A[i][2];
				stats_A[i][2] = stats_A[i + 1][2];
				stats_A[i + 1][2] = temp;
				temp = stats_A[i][3];
				stats_A[i][3] = stats_A[i + 1][3];
				stats_A[i + 1][3] = temp;
				temp = points_A[i][0];
				points_A[i][0] = points_A[i + 1][0];
				points_A[i + 1][0] = temp;
			}
		}
	}

	//Rework for Conference B
	for(i = 0; i < count_B; i++){
		for( j = i + 1; j < count_B; j++){
			if(points_B[i][0] < points_B[j][0]){
				strcpy(tempc, team_B[i]);
				strcpy(team_B[i], team_B[j]);
				strcpy(team_B[j], tempc);
				temp = played_B[i][0];
				played_B[i][0] = played_B[j][0];
				played_B[j][0] = temp;
				temp = stats_B[i][0];
				stats_B[i][0] = stats_B[j][0];
				stats_B[j][0] = temp;
				temp = stats_B[i][1];
				stats_B[i][1] = stats_B[j][1];
				stats_B[j][1] = temp;
				temp = stats_B[i][2];
				stats_B[i][2] = stats_B[j][2];
				stats_B[j][2] = temp;
				temp = stats_B[i][3];
				stats_B[i][3] = stats_B[j][3];
				stats_B[j][3] = temp;
				temp = points_B[i][0];
				points_B[i][0] = points_B[j][0];
				points_B[j][0] = temp;
			}
		}
	}

	for(i = 0; i < count_B; i++){
		if(points_B[i][0] == points_B[i + 1][0]){
			if(strcmp(team_B[i],team_B[i + 1]) < 0){
				strcpy(tempc, team_B[i]);
				strcpy(team_B[i], team_B[i + 1]);
				strcpy(team_B[i + 1], tempc);
				temp = played_B[i][0];
				played_B[i][0] = played_B[i + 1][0];
				played_B[i + 1][0] = temp;
				temp = stats_B[i][0];
				stats_B[i][0] = stats_B[i + 1][0];
				stats_B[i + 1][0] = temp;
				temp = stats_B[i][1];
				stats_B[i][1] = stats_B[i + 1][1];
				stats_B[i + 1][1] = temp;
				temp = stats_B[i][2];
				stats_B[i][2] = stats_B[i + 1][2];
				stats_B[i + 1][2] = temp;
				temp = stats_B[i][3];
				stats_B[i][3] = stats_B[j][3];
				stats_B[i + 1][3] = temp;
				temp = points_B[i + 1][0];
				points_B[i][0] = points_B[j][0];
				points_B[i + 1][0] = temp;
			}
		}
	}

	/* Table One Layout */

	//Print Conference A
	printf("%-25s%s%7s%7s%7s%7s%8s\n", conference_A, "GP", "W", "L", "OTL", "SL", "PTS");
	for(i = 0; i < count_A; i++){
		printf("%-25s%d%7d%7d%7d%7d%7d\n",team_A[i], played_A[i][0], stats_A[i][0], stats_A[i][1], stats_A[i][2], stats_A[i][3], points_A[i][0]);
	}

	printf("\n");

	//Print Conference B
	printf("%-25s%s%7s%7s%7s%7s%8s\n", conference_B, "GP", "W", "L", "OTL", "SL", "PTS");
	for(i = 0; i < count_B; i++){
		printf("%-25s%d%7d%7d%7d%7d%7d\n",team_B[i], played_B[i][0], stats_B[i][0], stats_B[i][1], stats_B[i][2], stats_B[i][3], points_B[i][0]);
	}

	printf("\n\n");

	/* Combined Table */

	int count_C = count_A + count_B;
	int played_C[count_C][1];
	int stats_C[count_C][4];
	int points_C[count_C][1];
	char team_C[count_C][26];

	// Transferring A Values to  C (index: from 0 - count_A)
	for(i = 0; i < count_A; i++){
		strcpy(team_C[i], team_A[i]);
		played_C[i][0] = played_A[i][0];
		stats_C[i][0] = stats_A[i][0];
		stats_C[i][1] = stats_A[i][1];
		stats_C[i][2] = stats_A[i][2];
		stats_C[i][3] = stats_A[i][3];
		points_C[i][0] = points_A[i][0];
	}

	// Transferring B Values to C (index: from count_A to count_C)
	for (i = 0; i < count_B; i++){
		strcpy(team_C[i + count_A], team_B[i]);
		played_C[i + count_A][0] = played_B[i][0];
		stats_C[i + count_A][0] = stats_B[i][0];
		stats_C[i + count_A][1] = stats_B[i][1];
		stats_C[i + count_A][2] = stats_B[i][2];
		stats_C[i + count_A][3] = stats_B[i][3];
		points_C[i + count_A][0] = points_B[i][0];
	}

	/* Overall Points from Greatest to Least */

	//Rework for Conference C
	for(i = 0; i < count_C; i++){
		for( j = i + 1; j < count_C; j++){
			if(points_C[i][0] < points_C[j][0]){
				// swap name
				strcpy(tempc, team_C[i]);
				strcpy(team_C[i], team_C[j]);
				strcpy(team_C[j], tempc);
				// swap GP
				temp = played_C[i][0];
				played_C[i][0] = played_C[j][0];
				played_C[j][0] = temp;
				// swap Wins
				temp = stats_C[i][0];
				stats_C[i][0] = stats_C[j][0];
				stats_C[j][0] = temp;
				// swap Losses
				temp = stats_C[i][1];
				stats_C[i][1] = stats_C[j][1];
				stats_C[j][1] = temp;
				// swap OTL
				temp = stats_C[i][2];
				stats_C[i][2] = stats_C[j][2];
				stats_C[j][2] = temp;
				// swap SL
				temp = stats_C[i][3];
				stats_C[i][3] = stats_C[j][3];
				stats_C[j][3] = temp;
				// swap points
				temp = points_C[i][0];
				points_C[i][0] = points_C[j][0];
				points_C[j][0] = temp;
			}
		}
	}

	for(i = 0; i < count_C - 1; i++){
		if(points_C[i][0] == points_C[i + 1][0]){
			if(strcmp(team_C[i],team_C[i + 1]) > 0){
				strcpy(tempc, team_C[i]);
				strcpy(team_C[i], team_C[i+1]);
				strcpy(team_C[i + 1], tempc);
				temp = played_C[i][0];
				played_C[i][0] = played_C[i + 1][0];
				played_C[i + 1][0] = temp;
				temp = stats_C[i][0];
				stats_C[i][0] = stats_C[i + 1][0];
				stats_C[i + 1][0] = temp;
				temp = stats_C[i][1];
				stats_C[i][1] = stats_C[i + 1][1];
				stats_C[i + 1][1] = temp;
				temp = stats_C[i][2];
				stats_C[i][2] = stats_C[i + 1][2];
				stats_C[i + 1][2] = temp;
				temp = stats_C[i][3];
				stats_C[i][3] = stats_C[i + 1][3];
				stats_C[i + 1][3] = temp;
				temp = points_C[i][0];
				points_C[i][0] = points_C[i + 1][0];
				points_C[i + 1][0] = temp;
			}
		}
	}

	/* Table Two Layout */

	//Print "WHL" Table
	printf("%-25s%s%7s%7s%7s%7s%8s\n", "WHL", "GP", "W", "L", "OTL", "SL", "PTS");
	for(i = 0; i < count_C; i++){
		printf("%-25s%d%7d%7d%7d%7d%7d\n",team_C[i], played_C[i][0], stats_C[i][0], stats_C[i][1], stats_C[i][2], stats_C[i][3], points_C[i][0]);
	}

	return EXIT_SUCCESS;
}
