<?hh // strict

/**
 * Markdown Parser
 * @author Nathan Davies, http://nathandavies.ninja
 * @copyright Copyright (c) 2016, Nathan Davies
 */

namespace Markdown\Helpers;

use Markdown\Helper;
use Markdown\Interfaces\BlockElement;

class Paragraph extends Helper implements BlockElement
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
	public static bool $isStandalone = false;

	/**
	 * @var string Parser regex
	 * Example: {content}   =>   <p>{content}</p>
	 */
	public static string $regex = "/(?<content>.*)/";

	/**
	 * Markup for the paragraph element
	 * @param array<array<string>> $content Lines within the paragraph, and their regex values: content
	 * @return string The markup
	 */
	public static function markup(array<array<string>> $content) : string
	{
		foreach ($content as $line)
			$markup [] = $line["content"];

		return parent::markup($markup, "p");
	}
}
