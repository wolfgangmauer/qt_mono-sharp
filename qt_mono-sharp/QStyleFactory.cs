using System.Runtime.CompilerServices;
using System;
using System.Collections.Generic;

namespace Qt
{
    public class StyleFactory
    {
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_stylefactory_create(string name);
		public static Style Create(string name)
        {
			var ptr = qt_stylefactory_create (name);
			return ptr == IntPtr.Zero ? null : new Style(ptr);
        }

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern string[] qt_stylefactory_keys ();
		public static string[] Keys
		{
			get
			{
				return qt_stylefactory_keys ();
			}
		}
    }
}
