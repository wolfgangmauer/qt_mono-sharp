using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.CompilerServices;
using System.Xml.Serialization;

namespace Qt
{
    public class Font
    {
		public IntPtr Handle { get; private set;}

        [MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern IntPtr qt_font_new();
        public Font()
        {
			Handle = qt_font_new();
        }

		public Font(IntPtr raw)
		{
			Handle = raw;
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_font_new_with_params(string family, int pointSize, int weight, bool italic);
		public Font(string family, int pointSize = -1, int weight = -1, bool italic = false)
		{
			Handle = qt_font_new_with_params(family, pointSize, weight, italic);
		}
			
        [MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern string qt_font_family_get(IntPtr raw);
        [MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern void qt_font_family_set(IntPtr raw, string family);
        public string Family
        {
            get
            {
				return qt_font_family_get(Handle);
            }
            set
            {
				qt_font_family_set(Handle, value);
            }
        }

        [MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern int qt_font_pointsize_get(IntPtr raw);
        [MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern void qt_font_pointsize_set(IntPtr raw, int pointsize);
        public int PointSize
        {
            get
            {
				return qt_font_pointsize_get(Handle);
            }
            set
            {
				qt_font_pointsize_set(Handle, value);
            }
        }
    }
}
