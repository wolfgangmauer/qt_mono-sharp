using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class ListView : AbstractItemView
	{
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_listview_new (IntPtr parent);

		protected ListView(IntPtr raw) : base(raw) { }

		public ListView (Object parent = null) : base(IntPtr.Zero)
		{
			Raw = qt_listview_new (parent != null ? parent.Handle : IntPtr.Zero);		
		}
	}
}

