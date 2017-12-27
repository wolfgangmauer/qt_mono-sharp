using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class EglFSFunctions
	{
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_eglfs_loadkeymap (string keymap);
		public static void LoadKeymap (string keymap)
		{
			qt_eglfs_loadkeymap (keymap);
		}
	}
}

