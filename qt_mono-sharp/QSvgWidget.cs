using System;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;

namespace Qt
{
    public class SvgWidget : Widget
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern IntPtr qt_svgwidget_new(SvgWidget thisObject, IntPtr parent);

        protected SvgWidget() { }

        protected SvgWidget(IntPtr raw) : base(raw) { }

        public SvgWidget(Widget parent)
            : base(IntPtr.Zero)
        {
            if (Raw != IntPtr.Zero)
                throw new ArgumentException("Raw not null!");
            Raw = qt_svgwidget_new(this, parent != null ? parent.Handle : IntPtr.Zero);
        }
        [MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern int qt_svgwidget_load(IntPtr handle, byte[] data);
        public void Load(Stream stream)
        {
            using (var byteReader = new BinaryReader(stream))
            {
                qt_svgwidget_load(Handle, byteReader.ReadBytes((int)stream.Length));
            }
        }
        public void Load(byte[] data)
        {
            qt_svgwidget_load(Handle, data);
        }
        [MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern IntPtr qt_svgwidget_sizehint_get(IntPtr raw);
        public new Size SizeHint
        {
            get { return new Size(qt_svgwidget_sizehint_get(Handle)); }
        }
    }
}
