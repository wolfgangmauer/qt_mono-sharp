using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
    public class CoreApplication : Object
    {
		protected static bool monointernal_init;
		[MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern IntPtr qt_coreapplication_new();

		protected CoreApplication(IntPtr raw) : base(raw) {}

        public CoreApplication(string[] argv) : base(IntPtr.Zero)
        {
			if (!monointernal_init)
                QtApplicationMonoInit();
            Raw = qt_coreapplication_new();
        }

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_coreapplication_quit();
		public static void Quit()
		{
			qt_coreapplication_quit ();
		}

		[DllImport("qt_mono-sharp", SetLastError = true)]
		public static extern void qt_application_monointernal_init();
		public static void QtApplicationMonoInit()
		{
			qt_application_monointernal_init ();
			monointernal_init = true;
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_application_attribute_set(ApplicationAttribute attribute);
		public static ApplicationAttribute Attribute
		{
			set
			{
				if (!monointernal_init)
                    QtApplicationMonoInit();
				qt_application_attribute_set (value);
			}
		}
    }
}
