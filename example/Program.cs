using System;
using Qt;
using System.Threading;

namespace TestQtMonoSharp
{
	class MainClass
	{
		delegate void HideFromJit(string[] args);

		public static void Main (string[] args)
		{
			HideFromJit d = StartUp;
			d (args);
		}

		public static void StartUp(string[] args)
		{
			GLib.Global.ProgramName = "ProgramName";

			CoreApplication.InitMonoInternal ();

			Application.Attribute = ApplicationAttribute.AA_EnableHighDpiScaling;

			var app = new Application (args);

			var mainWindow = new MyMainWindow ();
			mainWindow.FixedSize = new Size(1920/2, 1080/2);
			mainWindow.Show ();

			var splash = new MessagePanel (mainWindow);
			splash.Exec ();

			app.Exec ();
		}
	}
}
