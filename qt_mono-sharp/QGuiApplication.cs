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
                QtApplicationMonoInit();
            Raw = qt_guiapplication_new();
        }

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_guiapplication_primaryscreen_get();
		public static Screen PrimaryScreen
		{
			get{ return new Screen (qt_guiapplication_primaryscreen_get ()); }
		}
    }
}
