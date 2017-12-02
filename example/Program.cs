using System;
using Qt;
using System.Threading;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Drawing;

namespace TestQtMonoSharp
{
	class MainClass
	{
		[DllImport ("__Internal", EntryPoint = "mono_get_runtime_build_info")]
		public extern static string GetMonoVersion ();

		delegate void HideFromJit (string[] args);

		public static void Main (string[] args)
		{
			GLib.Global.ProgramName = "ProgramName";
			StartUp (args);
//			HideFromJit d = StartUp;
//			d (args);
		}

		public static void StartUp (string[] args)
		{
			CoreApplication.InitMonoInternal ();

			Application.Attribute = ApplicationAttribute.AA_EnableHighDpiScaling;

			var app = new Application (args);

			var mainWindow = new MyMainWindow ();
			mainWindow.FixedSize = new Size (1920 / 2, 1080 / 2);
			mainWindow.Show ();

			var splash = new MessagePanel ();
			splash.Exec ();

			app.Exec ();
		}
	}
}
