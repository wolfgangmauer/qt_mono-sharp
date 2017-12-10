using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class ModelIndex
	{
		public ModelIndex (int row, int col)
		{
			Row = row;
			Column = col;
		}

		public int Row {
			get ;
			private set;
		}

		public int Column
		{
			get ;
			private set;
		}

//		[MethodImpl (MethodImplOptions.InternalCall)]
//		protected static extern object qt_modelindex_data_get (IntPtr handle);
//		public object Data
//		{
//			get { return qt_modelindex_data_get (raw); }
//		}

//		[MethodImpl (MethodImplOptions.InternalCall)]
//		protected static extern ItemFlags qt_modelindex_flags_get (IntPtr handle);
//		public ItemFlags Flags
//		{
//			get { return qt_modelindex_flags_get (raw); }
//		}
	}
}

