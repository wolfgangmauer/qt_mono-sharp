using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class StandardItem
	{
		IntPtr raw;

		public IntPtr Handle { get { return raw; }}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_standarditem_new (string text);
		public StandardItem (string text)
		{
			raw = qt_standarditem_new (text);
		}
	}
}

