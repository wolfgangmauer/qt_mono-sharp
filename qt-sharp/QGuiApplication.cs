using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
    public class GuiApplication : CoreApplication
    {
		[MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern IntPtr qt_guiapplication_new();

		protected GuiApplication(IntPtr raw) : base(raw) {}

		public GuiApplication(string[] argv) : base(IntPtr.Zero)
        {
			if (!monointernal_init)
				InitMonoInternal ();
            Raw = qt_guiapplication_new();
        }
    }
}
