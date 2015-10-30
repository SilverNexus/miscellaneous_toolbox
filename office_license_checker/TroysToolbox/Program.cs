using System;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace TroysToolbox
{
    class Program
    {
        static void ShowOfficeStatus(string foundAt)
        {
            // Create a proccess to run the script
            ProcessStartInfo processInfo = new ProcessStartInfo();
            processInfo.FileName = "cscript";
            processInfo.Arguments = "\"" + foundAt + "\" /dstatus";
            processInfo.RedirectStandardOutput = true;
            processInfo.CreateNoWindow = false;
            processInfo.UseShellExecute = false;

            Process proc = Process.Start(processInfo);
            proc.WaitForExit();

            Console.WriteLine(proc.StandardOutput.ReadToEnd());
        }

        static void Main(string[] args)
        {
            bool found = false;
            if (System.Environment.Is64BitOperatingSystem)
            {
#if DEBUGGING
                Console.WriteLine("64-bit");
#endif
                string[] officePlaces64 = Directory.GetDirectories(@"C://Program Files/Microsoft Office/", "Office*");
                string[] officePlaces32 = Directory.GetDirectories(@"C://Program Files (x86)/Microsoft Office/", "Office*");
#if DEBUGGING
                Console.WriteLine("64-bit office:");
#endif
                string foundAt = "";
                foreach (String str in officePlaces64)
                {
#if DEBUGGING
                    Console.WriteLine(str);
#endif
                    string[] vbs = Directory.GetFiles(str, "ospp.vbs");
                    if (vbs.Length != 0)
                    {
                        found = true;
                        foundAt = str + "/ospp.vbs";
                    }
                }
#if DEBUGGING
                Console.WriteLine("32-bit office:");
#endif
                foreach (String str in officePlaces32)
                {
#if DEBUGGING
                    Console.WriteLine(str);
#endif
                    string[] vbs = Directory.GetFiles(str, "ospp.vbs");
                    if (vbs.Length != 0)
                    {
                        found = true;
                        foundAt = str + "/ospp.vbs";
                    }
                }
                if (!found)
                {
                    Console.WriteLine("Could not find ospp.vbs.");
                }
                else
                {
                    ShowOfficeStatus(foundAt);
                }
            }
            else
            {
#if DEBUGGING
                Console.WriteLine("32-bit");
#endif
                string[] officePlaces = Directory.GetDirectories(@"C://Program Files/Microsoft Office/", "Office*");
#if DEBUGGING
                Console.WriteLine("32-bit office:");
#endif
                string foundAt = "";
                foreach (String str in officePlaces)
                {
#if DEBUGGING
                    Console.WriteLine(str);
#endif
                    string[] vbs = Directory.GetFiles(str, "ospp.vbs");
                    if (vbs.Length != 0)
                    {
                        found = true;
                        foundAt = str + "/ospp.vbs";
                    }
                }
                if (!found)
                {
                    Console.WriteLine("Could not find ospp.vbs.");
                }
                else
                {
                    ShowOfficeStatus(foundAt);
                }
            }
            Console.ReadKey();
        }
    }
}
