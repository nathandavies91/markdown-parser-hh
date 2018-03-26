<?hh // strict

/**
 * Markdown Parser
 * @author Nathan Davies, http://nathandavies.ninja
 * @copyright Copyright (c) 2016, Nathan Davies
 */

namespace Markdown\Helpers;

use Markdown\Helper;
use Markdown\Interfaces\InlineElement;

class Image extends Helper implements InlineElement
{
	/**
	 * @var array<string> Parser regex
	 * Example 2: ![{alt}]({src})   =>   <img src="{src}" alt="{alt}" />
	 */
	public static array<string> $regex = array('/!\[(?<alt>.*?)\]\((?<src>.*?[^"])\)/');

	/**
	 * Markup for the image element
	 * @param array<string> $content Regex values: alt, src
	 * @return string The markup
	 */
	public static function markup(array<string> $content) : string
	{
		return "<img src=\"" . $content["src"] . "\" alt=\"" . $content["alt"] . "\" />";
	}
}
