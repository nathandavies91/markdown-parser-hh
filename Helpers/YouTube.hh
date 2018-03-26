<?hh // strict

/**
 * Markdown Parser
 * @author Nathan Davies, http://nathandavies.ninja
 * @copyright Copyright (c) 2016, Nathan Davies
 */

namespace Markdown\Helpers;

use Markdown\Helper;
use Markdown\Interfaces\BlockElement;

class YouTube extends Helper implements BlockElement
{
	/**
	 * @var bool
	 * Parse inline elements for this block?
	 */
	public static bool $includeInlines = false;

	/**
	 * @var bool
	 * Is the current block element independant (true)?
	 * Or can it contain other block elements (false)?
	 */
	public static bool $isStandalone = true;

	/**
	 * @var string Parser regex
	 * Example: ^[youtube]({content})   =>   ...
	 */
	public static string $regex = "/^\^\[youtube\]\((?<id>[a-zA-Z0-9-]{1,})\)/";

	/**
	 * Markup for the YouTube element
	 * @param array<string> $content The YouTube element; with its' regex values: content
	 * @return string The markup
	 */
	public static function markup(array<string> $content) : string
	{
		return "<iframe class=\"md-youtube\" src=\"https://www.youtube.com/embed/" . $content["id"] . "\" height=\"390\" width=\"640\"></iframe>";
	}
}
