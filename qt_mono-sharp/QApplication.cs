using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;
using System.Reflection;
using System.Collections.Generic;

namespace Qt
{
    public class Application : GuiApplication
    {
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_application_new(Application thisObject, string[] argv);

		public Application(string[] argv) : base(IntPtr.Zero)
        {
			if (!monointernal_init)
				InitMonoInternal ();
			var ass = Assembly.GetEntryAssembly ().CodeBase.Replace("file://", string.Empty);
			var list = new List<string> (argv);
			list.Insert (0, ass);
			Raw = qt_application_new(this, list.ToArray());
        }

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern int qt_application_exec(IntPtr raw);
		public int Exec()
		{
			var handle = GetObjectFromRaw (Handle);
			int retVal = qt_application_exec (handle.Handle);
			return retVal;
		}
    }
}
