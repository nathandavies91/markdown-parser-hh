<?hh // strict

/**
 * Markdown Parser
 * @author Nathan Davies, http://nathandavies.ninja
 * @copyright Copyright (c) 2016, Nathan Davies
 */

namespace Markdown\Helpers;

use Markdown\Helper;
use Markdown\Interfaces\BlockElement;

class Figure extends Helper implements BlockElement
{
	/**
	 * @var bool
	 * Parse inline elements for this block?
	 */
	public static bool $includeInlines = true;

	/**
	 * @var bool
	 * Is the current block element independant (true)?
	 * Or can it contain other block elements (false)?
	 */
	public static bool $isStandalone = true;

	/**
	 * @var string Parser regex
	 * [{caption}]({src} "{alt}")   =>   <figure><img src="{src}" alt="{alt}" /><figcaption>{caption}</figcaption></figure>
	 */
	public static string $regex = '/^!\[(?<caption>.*?)\]\((?<src>.*?) "(?<alt>.*?)"\)/';

	/**
	 * Markup for the figure element
	 * @param array<string> $content Regex values: alt, caption, src
	 * @return string The markup
	 */
	public static function markup(array<string> $content) : string
	{
		return parent::markup(Image::markup($content) . parent::markup($content["caption"], "figcaption"), "figure");
	}
}
