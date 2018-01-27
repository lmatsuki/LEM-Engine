#pragma once

// Specify the z-order for when the image is rendered.
// Made explicitly as old-style enum to keep the implicit conversion to int.
namespace ImageOrder
{
	enum DefaultImageOrder
	{
		Background,
		Static,
		Dynamic,
		GUI,
		Camera,
	};
}