using System.Text;

int nq = int.Parse(Console.ReadLine()!);
int[] next = new int[nq + 1];
Array.Fill(next, -1);

StringBuilder builder = new();
for (int i = 0; i < nq; ++i)
{
    int[] query = Console.ReadLine()!.Split(' ').Select(int.Parse).ToArray();
    if (query[0] == 1)
    {
        int x = query[1];
        int after = next[x];
        if (after >= 0) next[i + 1] = after;
        next[x] = i + 1;
    }
    else
    {
        int x = query[1], y = query[2];
        int n1 = x, n2 = y;
        long sum1 = 0, sum2 = 0;
        while (true)
        {
            if (n1 >= 0)
            {
                n1 = next[n1];
                if (n1 == y)
                {
                    builder.AppendLine(sum1.ToString());
                    next[x] = y;
                    break;
                }
                sum1 += n1;
            }
            if (n2 >= 0)
            {
                n2 = next[n2];
                if (n2 == x)
                {
                    builder.AppendLine(sum2.ToString());
                    next[y] = x;
                    break;
                }
                sum2 += n2;
            }
        }
    }
}
Console.WriteLine(builder.ToString());

// 238ms
