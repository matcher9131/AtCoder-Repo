using System.Diagnostics;
namespace Typical90_032
{
    public class Program
    {
        static void Main(string[] args)
        {
            Stopwatch sw = new();
            sw.Start();
            Answer2.Run();
            sw.Stop();
            Console.WriteLine($"{sw.ElapsedMilliseconds}msec");
        }
    }
}