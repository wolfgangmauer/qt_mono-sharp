using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
    public class HeaderView : ItemView
    {
		public enum ResizeMode
		{
			Interactive,
			Stretch,
			Fixed,
			ResizeToContents,
			Custom = Fixed
		}

		public HeaderView(IntPtr raw) : base(raw) { }

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_headerview_visible_set (IntPtr raw, bool visible);
		public bool Visible
		{
			set{ qt_headerview_visible_set (Handle, value); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern ResizeMode qt_headerview_section_resizemode_get (IntPtr raw, int logicalIndex);
		public ResizeMode GetSectionResizeMode(int logicalIndex)
		{
			return qt_headerview_section_resizemode_get (Handle, logicalIndex);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_headerview_section_resizemode_index_set (IntPtr raw, int logicalIndex, ResizeMode mode);
		public void SetSectionResizeMode(int logicalIndex, ResizeMode mode)
		{
			qt_headerview_section_resizemode_index_set (Handle, logicalIndex, mode);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_headerview_section_resizemode_set (IntPtr raw, ResizeMode mode);
		public void SetSectionResizeMode(ResizeMode mode)
		{
			qt_headerview_section_resizemode_set (Handle, mode);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_headerview_sectionsize_get (IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_headerview_sectionsize_set (IntPtr raw, int size);
		public int DefaultSectionSize
		{
			get
			{
				return qt_headerview_sectionsize_get (Handle);
			}
			set 
			{
				qt_headerview_sectionsize_set (Handle, value);
			}
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern Qt.Alignment qt_headerview_defaultalignment_get (IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_headerview_defaultalignment_set (IntPtr raw, Qt.Alignment alignment);
		public Qt.Alignment DefaultAlignment
		{
			get
			{
				return qt_headerview_defaultalignment_get (Handle);
			}
			set 
			{
				qt_headerview_defaultalignment_set (Handle, value);
			}
		}
    }
}
