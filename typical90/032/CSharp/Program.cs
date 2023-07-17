using BenchmarkDotNet.Running;

namespace Typical90_032
{
    public class Program
    {
        static void Main(string[] args)
        {
            var summary = BenchmarkRunner.Run<Methods>();
        }
    }
}