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
				InitMonoInternal ();
            Raw = qt_coreapplication_new();
        }

		[DllImport("qt_mono-sharpglue", SetLastError = true)]
		public static extern void qt_application_monointernal_init();
		public static void InitMonoInternal()
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
					InitMonoInternal ();
				qt_application_attribute_set (value);
			}
		}
    }
}
