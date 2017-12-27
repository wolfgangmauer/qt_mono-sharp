using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class ProgressBar : Widget
	{
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_progressbar_new (ProgressBar thisObject, IntPtr parent);
		public ProgressBar (IntPtr parent) : base(IntPtr.Zero)
		{
			if (Raw != IntPtr.Zero)
				throw new ArgumentException ("Raw not null!");
			Raw = qt_progressbar_new (this, parent);
		}

		public ProgressBar (Widget parent) : base(IntPtr.Zero)
		{
			if (Raw != IntPtr.Zero)
				throw new ArgumentException ("Raw not null!");
			Raw = qt_progressbar_new (this, parent != null ? parent.Handle : IntPtr.Zero);		
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern int qt_progressbar_value_get(IntPtr raw);
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_progressbar_value_set(IntPtr raw, int indent);
		public int Value
		{
			get
			{
				return qt_progressbar_value_get(Handle);
			}
			set
			{
				qt_progressbar_value_set(Handle, value);
			}
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern string qt_progressbar_format_get(IntPtr raw);
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_progressbar_format_set(IntPtr raw, string format);
		public string Format
		{
			get
			{
				return qt_progressbar_format_get(Handle);
			}
			set
			{
				qt_progressbar_format_set(Handle, value);
			}
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern int qt_progressbar_minimum_get(IntPtr raw);
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_progressbar_minimum_set(IntPtr raw, int indent);
		public int Minimum
		{
			get
			{
				return qt_progressbar_minimum_get(Handle);
			}
			set
			{
				qt_progressbar_minimum_set(Handle, value);
			}
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern int qt_progressbar_maximum_get(IntPtr raw);
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_progressbar_maximum_set(IntPtr raw, int indent);
		public int Maximum
		{
			get
			{
				return qt_progressbar_maximum_get(Handle);
			}
			set
			{
				qt_progressbar_maximum_set(Handle, value);
			}
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_progressbar_range_set(IntPtr raw, int min, int max);
		public void SetRange(int min, int max)
		{
			qt_progressbar_range_set (Handle, min, max);
		}
	}
}

