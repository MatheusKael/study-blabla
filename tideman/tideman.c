#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{

    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            // printf("rank %i\n", rank);
            // printf("i is %i\n", i);
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            // i preferred over j - ranks[0] preferred over ranks[1]
            if (i < j)
            {

                preferences[ranks[i]][ranks[j]]++;
            }
            // printf("%i", preferences[i][j]);
        }
    }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {

        for (int j = 0; j < candidate_count; j++)
        {
            // i preferred over j
            if (i != j && (i == j - 1 || i == j + 1))
            {

                if (preferences[i][j] > preferences[j][i])
                {
                    pairs[pair_count].winner = i;
                    pairs[pair_count].loser = j;
                    pair_count++;
                }
            }
            else if (i != j && (i == j + (candidate_count - 1) || i == j - (candidate_count - 1)))
            {
                if (preferences[i][j] > preferences[j][i])
                {
                    pairs[pair_count].winner = i;
                    pairs[pair_count].loser = j;
                    pair_count++;
                }
            }
        }

        // printf("%i, %i\n", pairs[i].winner, pairs[i].loser);
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO

    for (int i = 0; i < pair_count; i++)
    {
        for (int j = i + 1; j < pair_count; j++)
        {
            int first = preferences[pairs[i].winner][pairs[i].loser];
            int second = preferences[pairs[i].loser][pairs[i].winner];
            int firstj = preferences[pairs[j].winner][pairs[j].loser];
            int secondj = preferences[pairs[j].loser][pairs[j].winner];
            if (first - second < firstj - secondj)
            {
                pair tmp = pairs[j];
                pairs[j] = pairs[i];
                pairs[i] = tmp;
            }
        }
        // printf("%i, %i\n", pairs[i].winner, pairs[i].loser);
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        if ( pairs[pair_count - 1].loser == pairs[pair_count - 2].winner && i == pair_count - 1 )
        {
            continue;
        }
        else
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    // for (int i = 0; i < candidate_count; i++)
    // {
    //     for (int j = 0; j < candidate_count; j++)
    //     {
    //         printf("%i", locked[i][j]);
    //     }
    //     printf("\n");
    // }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    int count_ones = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            //    printf("%i", locked[j][i]);
            if (locked[j][i] == 1)
            {
                count_ones++;
            }
            if (candidate_count - 1 == j && count_ones == 0)
            {
                printf("%s\n", candidates[i]);
            }
        }
        count_ones = 0;
        // printf("\n");
    }

    return;
}