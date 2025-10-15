static T[] ReadLine<T>() where T : System.Numerics.INumber<T>
{
    var line = Console.ReadLine()!.AsSpan();
    int count = 1;
    for (int i = 0; i < line.Length; ++i)
        if (line[i] == ' ') ++count;

    var result = new T[count];
    int index = 0, start = 0;
    for (int i = 0; i <= line.Length; ++i)
    {
        if (i == line.Length || line[i] == ' ')
        {
            result[index++] = T.Parse(line.Slice(start, i - start), System.Globalization.NumberStyles.Float, System.Globalization.CultureInfo.InvariantCulture);
            start = i + 1;
        }
    }
    return result;
}