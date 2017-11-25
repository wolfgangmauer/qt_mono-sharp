﻿using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
	public enum ResizeMode
	{
		Interactive,
		Stretch,
		Fixed,
		ResizeToContents,
		Custom = Fixed
	}

    public class HeaderView : AbstractItemView
    {
		public HeaderView(IntPtr raw) : base(raw) { }
    }
}