using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class ModelIndex
	{
		public IntPtr Handle { get ; private set; }

		public ModelIndex (IntPtr raw)
		{
			Handle = raw;
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_modelindex_row_get (IntPtr raw);
		public int Row 
		{
			get 
			{
				return qt_modelindex_row_get (Handle);
			}
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_modelindex_col_get (IntPtr raw);
		public int Column
		{
			get 
			{
				return qt_modelindex_col_get (Handle);
			}
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern ItemFlags qt_modelindex_flags_get (IntPtr handle);
		public ItemFlags Flags
		{
			get { return qt_modelindex_flags_get (Handle); }
		}
	}
}

