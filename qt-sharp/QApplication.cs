using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

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
			Raw = qt_application_new(this, argv);
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
